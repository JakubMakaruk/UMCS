import java.util.Stack;

public class Plus implements Wyrazenie {
    public void interpretuj(Stack<Integer> stos) {
        stos.push(stos.pop() + stos.pop());
    }
}

