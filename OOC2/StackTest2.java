public class StackTest2 {
    private Double[] doubleElements = {1.1, 2.2, 3.3, 4.4, 5.5};
    private Integer[] integerElements = {1, 2, 3, 4, 5};

    private Stack<Double> doubleStack;
    private Stack<Integer> integerStack;

    public void testStacks() {
        doubleStack = new Stack<Double> (5);
        integerStack = new Stack<Integer> (5);

        testPush("doubleStack", doubleStack, doubleElements);
        testPop("doubleStack", doubleStack);
        testPush("integerStack", integerStack, integerElements);
        testPop("integerStack", integerStack);
    }

    public <T> void testPush(String name, Stack<T> stack, T[] elements) {
        try {
            System.out.println("\nPushing elements onto doubleStack");;

            for(T element: elements) {
                System.out.printf("%s ", element);
                stack.push(element);
            }
        } 
        catch (FullStackException fullStackException) {
            System.err.println();
            fullStackException.printStackTrace();
        }
    }

    public <T> void testPop(String name, Stack<T> stack) {
        try {
            System.out.println("\nPopping elements from doubleStack");;

            T popValue;
            while(true) {
                popValue=stack.pop();
                System.out.printf("%s ", popValue);
            }
        } 
        catch (EmptyStackException emptyStackException) {
            System.err.println();
            emptyStackException.printStackTrace();
        }
    }

    public static void main(String[] args) {
        StackTest2 application = new StackTest2();
        application.testStacks();
    }
}
