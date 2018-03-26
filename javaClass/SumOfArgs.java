public class SumOfArgs {
    public static void main(String[] args) {
        int sum = 0;

        for (int i = 0; i < args.length; i++) {
            sum += checkInteger(args[i]);
        }
        System.out.println(sum);
    }

    private static int checkInteger(String s) {
        int result;
        try {
            result = Integer.parseInt(s);
        } catch(NumberFormatException e) {
            return 0;
        }
        return result;
    }
}