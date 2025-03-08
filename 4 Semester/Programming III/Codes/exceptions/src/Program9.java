public class Program9 {
    // Level 1 - Base exception
    static class Level1_Exc extends Exception {
        public Level1_Exc(String msg) {
            super(msg);
        }
    }

    // Level 2 - Inherits from base
    static class Level2_Exc extends Level1_Exc {
        public Level2_Exc(String msg) {
            super(msg);
        }
    }

    // Level 3 - Inherits from exception level 2
    static class Level3_Exc extends Level2_Exc {
        public Level3_Exc(String msg) {
            super(msg);
        }
    }

    static class A{
        public void method() throws Level1_Exc {
            throw new Level1_Exc("Level 1 exception: from A class");
        }
    }

    static class B extends A{
        @Override
        public void method() throws Level2_Exc {
            throw new Level2_Exc("Level 2 exception: from B class");
        }
    }

    static class C extends B{
        @Override
        public void method() throws Level3_Exc {
            throw new Level3_Exc("Level 3 exception: from C class");
        }
    }

    public static void main(String[] args) {
        A object = new C();
        try{
            object.method();
        }
        catch (Program9.Level1_Exc e) {
            System.out.println(e.getMessage());
        }
    }
}


