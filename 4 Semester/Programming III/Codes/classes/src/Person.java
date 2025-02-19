// Exercise 4 - Cesar Andres Zuleta Malanco

import javax.swing.*;
import java.util.Random;

// NOTE: BMI stands for Body Mass Index (Indice de Masa Corporal - IMC)
public class Person {
    private String name;
    private int age;
    private String id = "";
    private char sex;
    private float weight;
    private float height;

    Person(String name) {
        this.name = name;
        id = generateID();
    }

    public void setName(String name) {
        this.name = name;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public void setSex(char sex){
        this.sex = sex;
    }
    public void setWeight(float weight){
        this.weight = weight;
    }
    public void setHeight(float height){
        this.height = height;
    }

    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
    public float getWeight() {
        return weight;
    }
    public float getHeight() {
        return height;
    }

    public int calculateBMI(){
        float heightInMeters = height / 100;
        float bmi = (float) (weight / (Math.pow(heightInMeters, 2)));
        if(bmi < 20){
            return -1;
        }else if(bmi>=20 && bmi<25){
            return 0;
        }
        // else if(bmi>25)
        return 1;
    }

    public boolean isAdult(){
        return age >= 18;
    }

    private char checkSex(char s){
        if(s == 'M'){
            return 'M';
        }else if(s == 'F'){
            return 'F';
        }
        return 'H';
    }

    public void showData(){
        String person = "ID: " + id + "\n" + "Name: " + name + "\n" + "Age: " + age + "\n" + "Sex: " + sex + "\n" +
                "Weight: " + weight + " kg\n" + "Height: " + height + " cm";
        JOptionPane.showMessageDialog(null, person, name + " Data",
                JOptionPane.INFORMATION_MESSAGE);
    }

    private String generateID(){
        StringBuilder auxID = new StringBuilder();
        Random rand = new Random();
        int number = 100 + rand.nextInt(999-100 + 1);
        String num = Integer.toString(number);
        if (name != null && name.length() >=3) {
            auxID.append(name.charAt(0)).append(name.charAt(1)).append(name.charAt(2)).append(num);
        }else if(name!=null && !name.isEmpty()){
            auxID.append(name).append(num);
        }else{
            auxID.append("DEF");
        }
        return auxID.toString();
    }
}

class FourthMain{
    public static void main(String[] args) {
        Person[] people = new Person[3];

        for(int i = 0; i< people.length; i++){
            String name;
            int age;
            String sex;
            float weight;
            float height;

            name = (JOptionPane.showInputDialog("Enter name: "));
            try{
                age = Integer.parseInt(JOptionPane.showInputDialog("Enter age: "));
            }catch(NumberFormatException e) {
                JOptionPane.showMessageDialog(null, e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
                i--;
                continue;
            }
            while(true){
                sex = JOptionPane.showInputDialog("Enter sex (M/F): ");
                if(sex != null && sex.length() == 1 && (sex.equalsIgnoreCase("M") ||
                        sex.equalsIgnoreCase("F"))){
                    break;
                }
                JOptionPane.showMessageDialog(null, "Please enter a valid single character: 'M' or 'F'",
                        "Error", JOptionPane.ERROR_MESSAGE);
            }
            try{
                weight = Float.parseFloat(JOptionPane.showInputDialog("Enter weight (kg): "));

                height = Float.parseFloat(JOptionPane.showInputDialog("Enter height (cm): "));
            }catch(NullPointerException e) {
                JOptionPane.showMessageDialog(null, e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
                i--;
                continue;
            }

            people[i] = new Person(name);

            people[i].setName(name);
            people[i].setAge(age);
            people[i].setSex(sex.charAt(0));
            people[i].setWeight(weight);
            people[i].setHeight(height);


            int bmi = people[i].calculateBMI();
            if(bmi == -1){
                JOptionPane.showMessageDialog(null, people[i].getName() + " is at a healthy weigh");
            }else if(bmi == 0){
                JOptionPane.showMessageDialog(null, people[i].getName() + " is at a underweight");
            }else if(bmi == 1){
                JOptionPane.showMessageDialog(null, people[i].getName() + " is overweight");
            }
            if(people[i].isAdult()){
                JOptionPane.showMessageDialog(null, people[i].getName() + " is an adult");
            }else{
                JOptionPane.showMessageDialog(null, people[i].getName() + " is not an adult");
            }

            people[i].showData();
        }
    }
}
