import java.util.Stack;

public class Liczba implements Wyrazenie {
    private int liczba;

    public Liczba(int i) {
        liczba = i;
    }

    public void interpretuj(Stack<Integer> stos) {
        stos.push(liczba);
    }
}

