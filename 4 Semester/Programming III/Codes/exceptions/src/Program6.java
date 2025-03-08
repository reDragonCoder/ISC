public class Program6 {
    public static class CustomException1 extends Exception {
        public CustomException1(String msg){
            super(msg);
        }
    }

    public static class CustomException2 extends Exception {
        public CustomException2(String msg){
            super(msg);
        }
    }

    public static class CustomException3 extends Exception {
        public CustomException3(String msg){
            super(msg);
        }
    }

    public void exceptionThrower(int opt) throws CustomException1, CustomException2, CustomException3 {
        switch (opt){
            case 1:
                throw new CustomException1("Exception 1");
            case 2:
                throw new CustomException2("Exception 2");
            case 3:
                throw new CustomException3("Exception 3");
        }
    }

    public static void main(String[] args) {
        Program6 test = new Program6();
        try{
            test.exceptionThrower(1);
            test.exceptionThrower(2);
            test.exceptionThrower(3);
        }
        catch (CustomException1 | CustomException2 | CustomException3 e){
            System.out.println(e.getMessage());
        }
    }
}
