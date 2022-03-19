import java.util.ArrayList;

public class WildcardTest {
    public static void main(String[] args) {
        Integer[] ints={1, 2, 3, 4, 5};
        ArrayList<Integer> intList = new ArrayList<Integer>();

        for(Integer element: ints)
            intList.add(element);
        
        System.out.printf("intList contains: %s%n", intList);
        System.out.printf("Sum of elemets in intList: %.0f%n", sum(intList));

        Double[] d={1.1, 2.2, 3.2, 4.4, 5.5};
        ArrayList<Double> dList = new ArrayList<Double>();

        for(Double element: d)
            dList.add(element);
        
        System.out.printf("intList contains: %s%n", dList);
        System.out.printf("Sum of elemets in intList: %.1f%n", sum(dList));

        Number[] numbers = {1, 2.4, 3, 4.1};
        ArrayList<Number> numberList = new ArrayList<Number>();

        for (Number element: numbers)
            numberList.add(element);

        System.out.printf("numberList contains: %s%n", numberList);
        System.out.printf("Sum of elemets in numberList: %.1f%n", sum(numberList));
    }

    public static double sum(ArrayList<? extends Number> list) {
        double total=0;
        for(Number element: list)
            total+= element.doubleValue();
        
        return total;
    }
}
