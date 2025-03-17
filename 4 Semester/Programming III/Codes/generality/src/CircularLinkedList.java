import javax.swing.JOptionPane;

class Node<T> {
    T data;
    Node<T> next;
    public Node(T data) {
        this.data = data;
        this.next = null;
    }
}

public class CircularLinkedList<T> {
    private Node<T> root;
    private int size;

    public CircularLinkedList() {
        root = null;
        size = 0;
    }

    public boolean empty() {
        return root == null;
    }

    public void pushFront(T data) {
        Node<T> newNode = new Node<>(data);
        if (empty()) {
            root = newNode;
            newNode.next = root;
        } else {
            Node<T> last = root;
            while (last.next != root) {
                last = last.next;
            }
            newNode.next = root;
            last.next = newNode;
            root = newNode;
        }
        size++;
    }

    public void pushBack(T data) {
        Node<T> newNode = new Node<>(data);
        if (empty()) {
            root = newNode;
        } else {
            Node<T> last = root;
            while (last.next != root) {
                last = last.next;
            }
            last.next = newNode;
        }
        newNode.next = root;
        size++;
    }

    public T front() {
        if (empty()) {
            return null;
        }
        return root.data;
    }

    public T back() {
        if (empty()) {
            return null;
        }
        Node<T> last = root;
        while (last.next != root) {
            last = last.next;
        }
        return last.data;
    }

    public void popFront() {
        if (empty()) {
            return;
        }
        if (size == 1) {
            root = null;
        } else {
            Node<T> last = root;
            while (last.next != root) {
                last = last.next;
            }
            root = root.next;
            last.next = root;
        }
        size--;
    }

    public void popBack() {
        if (empty()) {
            return;
        }
        if (size == 1) {
            root = null;
        } else {
            Node<T> current = root;
            while (current.next.next != root) {
                current = current.next;
            }
            current.next = root;
        }
        size--;
    }

    public int getSize() {
        return size;
    }

    public boolean find(T data) {
        if (empty()) {
            return false;
        }
        Node<T> temp = root;
        do {
            if (temp.data.equals(data)) {
                return true;
            }
            temp = temp.next;
        } while (temp != root);
        return false;
    }

    public String toShow() {
        if (empty()) {
            return "The list is empty.";
        }
        StringBuilder sb = new StringBuilder();
        Node<T> temp = root;
        do {
            sb.append(temp.data.toString()).append("\n");
            temp = temp.next;
        } while (temp != root);
        return sb.toString();
    }
}

class Contact {
    private final String name;
    private final String address;
    private final String phone;
    private final String gender;

    public Contact(String name, String address, String phone, String gender) {
        this.name = name;
        this.address = address;
        this.phone = phone;
        this.gender = gender;
    }

    @Override
    public String toString() {
        return "Name: " + name + ", Address: " + address + ", Phone: " + phone + ", Gender: " + gender;
    }
}

class PhoneAgenda {
    public static void main(String[] args) {
        CircularLinkedList<Contact> agenda = new CircularLinkedList<>();
        String continueInput = "";
        do {
            String name = JOptionPane.showInputDialog(null, "Enter contact name:");
            if (name == null || name.trim().isEmpty()) {
                JOptionPane.showMessageDialog(null, "Name is required.");
                continue;
            }
            String address = JOptionPane.showInputDialog(null, "Enter contact address:");
            String phone = JOptionPane.showInputDialog(null, "Enter contact phone:");
            String gender = JOptionPane.showInputDialog(null, "Enter contact gender:");
            Contact newContact = new Contact(name, address, phone, gender);
            agenda.pushBack(newContact);
            continueInput = JOptionPane.showInputDialog(null, "Do you want to add another contact? (yes/no)");
        } while (continueInput != null && continueInput.equalsIgnoreCase("yes"));
        String agendaList = agenda.toShow();
        JOptionPane.showMessageDialog(null, "Phone Agenda:\n" + agendaList);
    }
}
