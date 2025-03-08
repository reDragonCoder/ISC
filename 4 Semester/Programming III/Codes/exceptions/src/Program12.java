import java.util.ArrayList;
import java.util.List;

public class Program12 {

    public static abstract class Account {
        private final String nic;
        protected double balance;

        protected Account(String nic, double balance) {
            this.balance = balance;
            this.nic = nic;
        }

        public abstract void withdraw(double amount) throws NegativeBalance;

        public double getBalance() {
            return balance;
        }

        public String getNic() {
            return nic;
        }

        @Override
        public abstract String toString();
    }

    public static class NegativeBalance extends Exception {
        public NegativeBalance(String msg) {
            super(msg);
        }
    }

    public static class NormalAccount extends Account {
        private SavingsAccount linkedSavingsAccount;

        public NormalAccount(String nic, double balance) {
            super(nic, balance);
        }

        public NormalAccount(String nic, double balance, SavingsAccount linkedSavingsAccount) {
            super(nic, balance);
            this.linkedSavingsAccount = linkedSavingsAccount;
        }

        @Override
        public void withdraw(double amount) throws NegativeBalance {
            if (amount <= balance) {
                balance -= amount;
            } else {
                double difference = amount - balance;
                balance = 0;
                if (linkedSavingsAccount != null) {
                    linkedSavingsAccount.withdraw(difference);
                } else {
                    balance -= difference;
                }
            }
        }

        @Override
        public String toString() {
            String info = "Normal Account - NIC: " + getNic() + ", Balance: " + balance;
            if (linkedSavingsAccount != null) {
                info += ", Linked Savings Account: " + linkedSavingsAccount.getNic();
            }
            return info;
        }
    }

    public static class SavingsAccount extends Account {
        public SavingsAccount(String nic, double balance) {
            super(nic, balance);
        }

        @Override
        public void withdraw(double amount) throws NegativeBalance {
            if (amount > balance) {
                throw new NegativeBalance("Cannot withdraw " + amount + " pesos from the Savings Account of "
                        + getNic() + " with balance " + balance);
            }
            balance -= amount;
        }

        @Override
        public String toString() {
            return "Savings Account - NIC: " + getNic() + ", Balance: " + balance;
        }
    }

    public static class SpecialSavingsAccount extends SavingsAccount {
        private final int penalty;

        public SpecialSavingsAccount(String nic, double balance, int penalty) {
            super(nic, balance);
            this.penalty = penalty;
        }

        @Override
        public void withdraw(double amount) throws NegativeBalance {
            double totalWithdraw = amount + (amount * penalty / 100.0);
            if (totalWithdraw > balance) {
                throw new NegativeBalance("Cannot withdraw " + amount
                        + " pesos (plus penalty) from the Special Savings Account of "
                        + getNic() + " with balance " + balance);
            }
            balance -= totalWithdraw;
        }

        @Override
        public String toString() {
            return "Special Savings Account - NIC: " + getNic()
                    + ", Balance: " + balance + ", Penalty: " + penalty + "%";
        }

        public int getPenalty() {
            return penalty;
        }
    }

    public static class Bank {
        private final List<Account> accounts;

        public Bank() {
            accounts = new ArrayList<>();
        }

        public void addAccount(Account account) {
            accounts.add(account);
        }

        public List<Account> getAccounts() {
            return accounts;
        }

        public String totalMaxBalancePenalty() {
            double totalBalanceAcc = 0.0;
            int maxPenalty = 0;
            for (Account account : accounts) {
                if (account instanceof NormalAccount) {
                    totalBalanceAcc += account.getBalance();
                }
                if (account instanceof SpecialSavingsAccount) {
                    int pen = ((SpecialSavingsAccount) account).getPenalty();
                    if (pen > maxPenalty) {
                        maxPenalty = pen;
                    }
                }
            }
            return "Total Balance of Normal Accounts: " + totalBalanceAcc
                    + " | Max Penalty in Special Savings Accounts: " + maxPenalty + "%";
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (Account account : accounts) {
                sb.append(account.toString()).append("\n");
            }
            return sb.toString();
        }
    }

    public static void main(String[] args) {
        Bank bank = new Bank();

        NormalAccount na = new NormalAccount("NIC001", 500.0);
        SpecialSavingsAccount ssa = new SpecialSavingsAccount("NIC002", 300.0, 5);

        bank.addAccount(na);
        bank.addAccount(ssa);

        bank.addAccount(new NormalAccount("NIC003", 100.0));
        bank.addAccount(new NormalAccount("NIC004", 200.0));

        bank.addAccount(new SavingsAccount("NIC005", 150.0));
        bank.addAccount(new SavingsAccount("NIC006", 250.0));

        bank.addAccount(new SpecialSavingsAccount("NIC007", 400.0, 3));
        bank.addAccount(new SpecialSavingsAccount("NIC008", 500.0, 7));

        SavingsAccount sAssociate = new SavingsAccount("NIC009", 100.0);
        NormalAccount na2 = new NormalAccount("NIC010", 50.0, sAssociate);
        bank.addAccount(na2);
        bank.addAccount(sAssociate);

        System.out.println("----------- Bank Account Information -----------");
        System.out.println(bank);

        System.out.println(bank.totalMaxBalancePenalty());

        try {
            System.out.println("\nTrying to withdraw 200 pesos from the SavingsAccount with NIC005:");
            SavingsAccount savingsAccount = null;
            for (Account account : bank.getAccounts()) {
                if (account instanceof SavingsAccount && account.getNic().equals("NIC005")) {
                    savingsAccount = (SavingsAccount) account;
                    break;
                }
            }
            if (savingsAccount != null) {
                savingsAccount.withdraw(200.0);
                System.out.println("New balance: " + savingsAccount.getBalance());
            } else {
                System.out.println("Savings Account not found");
            }
        } catch (NegativeBalance e) {
            System.out.println(e.getMessage());
        }
    }
}
