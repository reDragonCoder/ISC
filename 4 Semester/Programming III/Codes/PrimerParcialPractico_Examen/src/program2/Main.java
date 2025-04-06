// Author: reDragonCoder

package program2;

import program2.characters.*;
import program2.characters.Character;
import program2.weapons.bladedWeapons.*;
import program2.weapons.firearms.*;
import program2.powers.lightPowers.*;
import program2.powers.darkPowers.*;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Character> characters = new ArrayList<>();

        // Ask for the number of warriors to create
        System.out.print("Enter the total number of warriors to create: ");
        int totalWarriors = scanner.nextInt();

        // Ask how many will be swordsmen and gunmen
        System.out.print("Enter the number of swordsmen: ");
        int numSwordsmen = scanner.nextInt();
        System.out.print("Enter the number of gunmen: ");
        int numGunmen = scanner.nextInt();

        // Validate the sum matches the total number of warriors
        while (numSwordsmen + numGunmen != totalWarriors) {
            System.out.println("The sum of swordsmen and gunmen does not match the total number of warriors.");
            System.out.print("Enter the number of swordsmen again: ");
            numSwordsmen = scanner.nextInt();
            System.out.print("Enter the number of gunmen again: ");
            numGunmen = scanner.nextInt();
        }

        scanner.nextLine();

        // Create swordsmen
        System.out.println("\n--- Creation of Swordsmen ---");
        for (int i = 0; i < numSwordsmen; i++) {
            System.out.print("Enter the name of swordsman #" + (i + 1) + ": ");
            String name = scanner.nextLine();

            // Select the bladed weapon
            BladedWeapon bladedWeapon = chooseBladedWeapon(scanner);

            // Create the warrior and assign the type based on the weapon
            Warrior swordsman = new Warrior(name, 100, "Swordsman", bladedWeapon);
            characters.add(swordsman);
        }

        // Create gunmen
        System.out.println("\n--- Creation of Gunmen ---");
        for (int i = 0; i < numGunmen; i++) {
            System.out.print("Enter the name of gunman #" + (i + 1) + ": ");
            String name = scanner.nextLine();

            // Select the firearm
            Firearm firearm = chooseFirearm(scanner);

            // Create the warrior and assign the type based on the weapon
            Warrior gunman = new Warrior(name, 100, "Gunman", firearm);
            characters.add(gunman);
        }

        // Ask for the number of wizards to create
        System.out.print("\nEnter the total number of wizards to create: ");
        int totalWizards = scanner.nextInt();

        // Ask how many will have light and dark powers
        System.out.print("Enter the number of wizards with light powers: ");
        int numLightWizards = scanner.nextInt();
        System.out.print("Enter the number of wizards with dark powers: ");
        int numDarkWizards = scanner.nextInt();

        // Validate the sum matches the total number of wizards
        while (numLightWizards + numDarkWizards != totalWizards) {
            System.out.println("The sum of light and dark wizards does not match the total number of wizards.");
            System.out.print("Enter the number of wizards with light powers again: ");
            numLightWizards = scanner.nextInt();
            System.out.print("Enter the number of wizards with dark powers again: ");
            numDarkWizards = scanner.nextInt();
        }

        scanner.nextLine();

        // Create wizards with light powers
        System.out.println("\n--- Creation of Wizards with Light Powers ---");
        for (int i = 0; i < numLightWizards; i++) {
            System.out.print("Enter the name of light wizard #" + (i + 1) + ": ");
            String name = scanner.nextLine();

            // Select the light power
            LightPower lightPower = chooseLightPower(scanner);

            // Create the wizard
            Wizard lightWizard = new Wizard(name, lightPower);
            characters.add(lightWizard);
        }

        // Create wizards with dark powers
        System.out.println("\n--- Creation of Wizards with Dark Powers ---");
        for (int i = 0; i < numDarkWizards; i++) {
            System.out.print("Enter the name of dark wizard #" + (i + 1) + ": ");
            String name = scanner.nextLine();

            // Select the dark power
            DarkPower darkPower = chooseDarkPower(scanner);

            // Create the wizard
            Wizard darkWizard = new Wizard(name, darkPower);
            characters.add(darkWizard);
        }

        // Perform 10 random attacks with each character
        System.out.println("\n--- Performing Random Attacks with Characters ---");
        for (Character character : characters) {
            System.out.println("\n--- Actions of " + character.getName() + " ---");
            if (character instanceof Warrior warrior) {
                for (int i = 0; i < 10; i++) {
                    int energySpent = (int) (Math.random() * 20) + 1;
                    System.out.println("\nAttack #" + (i + 1) + " with energy spent: " + energySpent);
                    String result = warrior.fight(energySpent);
                    System.out.println(result);

                    // Randomly call the feed method at least 5 times
                    if (Math.random() < 0.5) { // 50% chance
                        int energyRecovered = (int) (Math.random() * 30) + 1;
                        System.out.println("Attempting to feed with " + energyRecovered + " energy.");
                        if (warrior.getEnergy() == warrior.getInitialEnergy()) {
                            System.out.println("Cannot increase energy beyond maximum.");
                        } else {
                            int energyBefore = warrior.getEnergy();
                            warrior.feed(energyRecovered);
                            System.out.println("Energy increased from " + energyBefore + " to " + warrior.getEnergy());
                        }
                    }

                    // If gunman, deplete all bullets and offer to reload
                    if (warrior.getWeapon() instanceof Firearm firearm) {
                        if (firearm.getCartridge() == 0) {
                            System.out.print("The cartridge is empty! Do you want to reload the weapon? (y/n): ");
                            String option = scanner.nextLine();
                            if (option.equalsIgnoreCase("y")) {
                                firearm.reload();
                                System.out.println("Weapon reloaded. Bullets available: " + firearm.getCartridge());
                            }
                        }
                    }

                    // If swordsman and edge is below 30%, offer to sharpen
                    if (warrior.getWeapon() instanceof BladedWeapon bladedWeapon) {
                        if (bladedWeapon.getCuttingEdge() < 30.0) {
                            System.out.print("The weapon's edge is below 30%. Do you want to sharpen it? (y/n): ");
                            String option = scanner.nextLine();
                            if (option.equalsIgnoreCase("y")) {
                                bladedWeapon.sharpen();
                                System.out.println("Weapon sharpened. Current edge: " + bladedWeapon.getCuttingEdge() + "%");
                            }
                        }
                    }
                }
            } else if (character instanceof Wizard wizard) {
                // Attempt to heal at the start (not possible)
                System.out.println("Attempting to heal at the start...");
                wizard.heal();

                for (int i = 0; i < 10; i++) {
                    System.out.println("Spell #" + (i + 1));
                    String result = wizard.castSpell();
                    System.out.println(result);

                    // Randomly call the feed method at least 5 times
                    if (Math.random() < 0.5) { // 50% chance
                        int energyRecovered = (int) (Math.random() * 30) + 1;
                        System.out.println("Attempting to feed with " + energyRecovered + " energy.");
                        if (wizard.getEnergy() == wizard.getInitialEnergy()) {
                            System.out.println("Cannot increase energy beyond maximum.");
                        } else {
                            int energyBefore = wizard.getEnergy();
                            wizard.feed(energyRecovered);
                            System.out.println("Energy increased from " + energyBefore + " to " + wizard.getEnergy());
                        }
                    }

                    // Attempt to heal after each spell
                    wizard.heal();
                }
            }
        }

        // Create a heterogeneous collection and attempt to attack with each character
        System.out.println("\n--- Attempting to attack with each character in the heterogeneous collection ---");
        for (Character character : characters) {
            System.out.println("\n" + character);
            if (character instanceof Warrior warrior) {
                System.out.println("Attacking with " + warrior.getName());
                warrior.fight(10);
            } else if (character instanceof Wizard wizard) {
                System.out.println("Attacking with " + wizard.getName());
                wizard.castSpell();
            } else {
                System.out.println("Cannot attack with " + character.getName() + " as they do not have an attack method.");
            }
        }

        // Call the overridden toString method in Character
        System.out.println("\n--- Information of characters using the overridden toString method ---");
        for (Character character : characters) {
            System.out.println(character.toString());
        }

        scanner.close();
    }

    // Methods to choose weapons and powers
    private static BladedWeapon chooseBladedWeapon(Scanner scanner) {
        System.out.println("Select the bladed weapon:");
        System.out.println("1. Katana");
        System.out.println("2. Gladius");
        System.out.println("3. Lightsaber");
        System.out.print("Option: ");
        int option = scanner.nextInt();
        scanner.nextLine();

        return switch (option) {
            case 1 -> new Katana();
            case 2 -> new Gladius();
            case 3 -> new Lightsaber();
            default -> {
                System.out.println("Invalid option. Katana will be assigned by default.");
                yield new Katana();
            }
        };
    }

    private static Firearm chooseFirearm(Scanner scanner) {
        System.out.println("Select the firearm:");
        System.out.println("1. Pistol");
        System.out.println("2. Rifle");
        System.out.println("3. Shotgun");
        System.out.print("Option: ");
        int option = scanner.nextInt();
        scanner.nextLine();

        return switch (option) {
            case 1 -> new Gun();
            case 2 -> new Rifle();
            case 3 -> new Shotgun();
            default -> {
                System.out.println("Invalid option. Pistol will be assigned by default.");
                yield new Gun();
            }
        };
    }

    private static LightPower chooseLightPower(Scanner scanner) {
        System.out.println("Select the light power:");
        System.out.println("1. Radiant Shield");
        System.out.println("2. Blinding Flash");
        System.out.println("3. Healing Beam");
        System.out.print("Option: ");
        int option = scanner.nextInt();
        scanner.nextLine();

        return switch (option) {
            case 1 -> new RadiantShield();
            case 2 -> new BlindingFlash();
            case 3 -> new HealingBeam();
            default -> {
                System.out.println("Invalid option. Radiant Shield will be assigned by default.");
                yield new RadiantShield();
            }
        };
    }

    private static DarkPower chooseDarkPower(Scanner scanner) {
        System.out.println("Select the dark power:");
        System.out.println("1. Shadow Cloak");
        System.out.println("2. Nightmare Tendrils");
        System.out.println("3. Void Rift");
        System.out.print("Option: ");
        int option = scanner.nextInt();
        scanner.nextLine();

        return switch (option) {
            case 1 -> new ShadowCloak();
            case 2 -> new NightmareTendrils();
            case 3 -> new VoidRift();
            default -> {
                System.out.println("Invalid option. Shadow Cloak will be assigned by default.");
                yield new ShadowCloak();
            }
        };
    }
}
