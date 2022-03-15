public class GenericMethodTest {
    public static <E> void printArray(E[] inputArray) {
        for(E element: inputArray)
            System.out.printf("%s ", element);
        System.out.println();
    }

    public static void main(String[] args) {
        Integer[] intArray={1, 2, 3, 4, 5};
        Double[] doubleArray={1.1, 2.2, 3.3, 4.4, 5.5};
        Character[] charArray={'a', 'b', 'c', 'd', 'e'};

        System.out.println("Array intArray contains: ");
        printArray(intArray);
        System.out.println("Array doubleArray contains: ");
        printArray(doubleArray);
        System.out.println("Array charArray contains: ");
        printArray(charArray);
    }

}

