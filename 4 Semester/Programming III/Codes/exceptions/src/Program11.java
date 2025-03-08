import java.util.Scanner;

public class Program11 {

    public static class IllegalTemperatureException extends Exception {
        IllegalTemperatureException(String msg) {
            super(msg);
        }
    }

    public static class Temperature{
        private double tempC;

        public void setC(double c) throws IllegalTemperatureException {
            if (c < -273.15) {
                throw new IllegalTemperatureException("The °C temperature cannot be lower than -273.15 °C");
            }
            this.tempC = c;
        }

        public void setK(double k) throws IllegalTemperatureException {
            if(k < 0){
                throw new IllegalTemperatureException("The °K temperature cannot be lower than 0 °K");
            }
            this.tempC = k - 273.15;
        }

        public double getC() {
            return tempC;
        }

        public double getK() {
            return tempC + 273.15;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Temperature temp = new Temperature();

        int option;
        do {
            System.out.println("\n--- Temperature menu ---");
            System.out.println("1. Enter temperature in Celsius degrees (ºC)");
            System.out.println("2. Enter temperature in Kelvin degrees (ºK)");
            System.out.println("3. Exit");
            System.out.print("Select an option: ");

            option = sc.nextInt();

            switch (option) {
                case 1:
                    System.out.print("Enter temperature in C°: ");
                    double c = sc.nextDouble();
                    try {
                        temp.setC(c);
                    } catch (IllegalTemperatureException e) {
                        throw new RuntimeException(e);
                    }
                    System.out.println("Temperature set correctly");
                    System.out.println("Value in ºC: " + temp.getC());
                    System.out.println("Value in ºK: " + temp.getK());
                    break;
                case 2:
                    System.out.print("Enter temperature in ºK: ");
                    double k = sc.nextDouble();
                    try {
                        temp.setK(k);
                    } catch (IllegalTemperatureException e) {
                        throw new RuntimeException(e);
                    }
                    System.out.println("Temperature set correctly");
                    System.out.println("Value in ºC: " + temp.getC());
                    System.out.println("Value in ºK: " + temp.getK());
                    break;
                case 3:
                    System.out.println("Leaving...");
                    break;
                default:
                    System.out.println("Non-valid option selected");
            }
        } while (option != 3);

        sc.close();
    }
}
