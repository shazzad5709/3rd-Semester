public class StackTest {
    private double[] doubleElements = {1.1, 2.2, 3.3, 4.4, 5.5};
    private int[] integerElements = {1, 2, 3, 4, 5};

    private Stack<Double> doubleStack;
    private Stack<Integer> integerStack;

    public void testStacks() {
        doubleStack = new Stack<Double> (5);
        integerStack = new Stack<Integer> (5);

        testPushDouble();
        testPopDouble();
        testPushInteger();
        testPushInteger();
    }
}
