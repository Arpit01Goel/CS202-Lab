public class Main {
    public static void main(String[] args) {
        double totalTime = 0;
        for (int i = 0; i < 200; i++) {
            totalTime += time();
        }
        totalTime /= 200;
        System.out.println(totalTime);
    }

    public static void fibb(int n) {
        double a = 0, b = 1, c = 1;
        for (int i = 0; i < n; i++) {
            a = b;
            b = c;
            c = a + b;
        }
        // a is now nth fibb
        // System.out.println(a);
    }

    public static double time() {
        long start = System.nanoTime();
        for (int i = 0; i < 50; i++) {
            fibb(100);
        }
        long end = System.nanoTime();
        double duration = (end - start) / 1_000_000.0; // Convert to milliseconds
        return duration;
    }
}