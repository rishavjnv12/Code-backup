public class p3{
    public static void main(String args[]) {
        if (args.length != 3) {
            System.out.println("Program terminated.");
            System.exit(0);
        }
        int args0 = Integer.parseInt(args[0]);
        int args2 = Integer.parseInt(args[2]);
        int arr[] = new int[args0];

        arr[0] = Integer.parseInt(args[1]);
        int i;
        for (i = 1; i < args0; i++) {
            arr[i] = arr[i - 1] + args2;
        }
        for (i = 0; i < args0; i++) {
            System.out.println(arr[i]);
        }
    }
}

