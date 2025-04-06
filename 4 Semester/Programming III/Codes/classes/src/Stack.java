// Exercise 7 - Author: reDragonCoder

import javax.swing.*;

public class Stack {
    // Nested Node class
    private static class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node top;

    public Stack() {
        top = null;
    }

    public void push(int data) {
        Node newNode = new Node(data);
        newNode.next = top;
        top = newNode;
    }

    public int pop() {
        if (isEmpty()) {
            throw new RuntimeException("Stack is empty. Cannot perform pop operation.");
        }
        int poppedData = top.data;
        top = top.next;
        return poppedData;
    }

    public boolean isEmpty() {
        return top == null;
    }

    public String getStackContents() {
        if (isEmpty()) {
            return "Stack is empty.";
        } else {
            StringBuilder contents = new StringBuilder();
            Node current = top;
            contents.append("Stack (top to bottom):\n");
            while (current != null) {
                contents.append(current.data).append("\n");
                current = current.next;
            }
            return contents.toString();
        }
    }
}

class SeventhMain{
    public static void main(String[] args) {
        Stack stack = new Stack();
        String[] options = {"Push", "Pop", "Print", "Exit"};
        int choice = -1;

        while (choice != 3) {
            choice = JOptionPane.showOptionDialog(
                    null,
                    "Choose an option:",
                    "Stack Operations",
                    JOptionPane.DEFAULT_OPTION,
                    JOptionPane.PLAIN_MESSAGE,
                    null,
                    options,
                    options[0]
            );

            switch (choice) {
                case 0: 
                    String input = JOptionPane.showInputDialog("Enter an integer to push onto the stack:");
                    try {
                        int value = Integer.parseInt(input);
                        stack.push(value);
                        JOptionPane.showMessageDialog(null, "Pushed " + value + " onto the stack.");
                    } catch (NumberFormatException e) {
                        JOptionPane.showMessageDialog(null, "Invalid input. Please enter an integer.");
                    }
                    break;

                case 1:
                    try {
                        int poppedValue = stack.pop();
                        JOptionPane.showMessageDialog(null, "Popped " + poppedValue + " from the stack.");
                    } catch (RuntimeException e) {
                        JOptionPane.showMessageDialog(null, e.getMessage());
                    }
                    break;

                case 2:
                    String stackContents = stack.getStackContents();
                    JOptionPane.showMessageDialog(null, stackContents);
                    break;

                case 3:
                    JOptionPane.showMessageDialog(null, "Exiting the program. Goodbye!");
                    break;

                default:
                    choice = 3;
                    break;
            }
        }
    }
}
