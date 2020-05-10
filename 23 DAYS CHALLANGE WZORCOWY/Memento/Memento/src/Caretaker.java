import java.util.ArrayList;

public class Caretaker {
    private Memento[] stany = new Memento[5];
    int index=0;

    public void dodajStan(Memento m) {
        stany[index] = m;
        index++;
    }

    public Memento getStan() {
        index--;
        return stany[index];
    }
}