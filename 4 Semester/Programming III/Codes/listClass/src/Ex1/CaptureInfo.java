package Ex1;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class CaptureInfo {
    public Person capturePerson(Scanner sc){
        Person person = new Person();

        System.out.println("Enter the name ");
        person.setName(sc.next());

        System.out.println("Enter the surname ");
        person.setSurname(sc.next());

        System.out.println("Enter the gender ");
        person.setGender(sc.next());

        System.out.println("Enter the age ");
        person.setAge(sc.nextInt());
        sc.nextLine();

        return person;
    }

    public double calculateAgeAverage(List<Person> list){
        if(list.isEmpty()){
            return 0;
        }
        int sum = 0;
        for(Person person : list){
            sum += person.getAge();
        }
        return (double)sum/list.size();
    }

    public Map<String, Integer> countByGender(List<Person> list){
        Map<String, Integer> counter = new HashMap<>();
        for (Person person : list) {
            String gender = person.getGender();
            counter.put(gender, counter.getOrDefault(gender, 0) + 1);
        }
        return counter;
    }
}
