public class MaximumTest {
    public static <T extends Comparable<T>> T maximum(T x, T y, T z) {
        T max=x;

        if(y.compareTo(max)>0)
            max=y;
        if(z.compareTo(max)>0)
            max=z;

        return max;
    }

    public static void main(String[] args) {
        System.out.printf("Maximum of %d, %d and %d is %d", 3, 4, 5, maximum(3, 4, 5));
        System.out.println();

    }
}

