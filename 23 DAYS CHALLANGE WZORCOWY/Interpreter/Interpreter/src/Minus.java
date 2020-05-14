import java.util.Stack;

public class Minus implements Wyrazenie {
    public void interpretuj(Stack<Integer> stos) {
        stos.push(stos.pop()*-1 + stos.pop());
    }
}

