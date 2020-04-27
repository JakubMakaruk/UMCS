package pack;
import java.util.*;
public class Bohater{
    public float x;
    public float y;

    public Bohater(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public Vector<Obserwator> obserwatorzy = new Vector<Obserwator>();

    public void zmienPolozenie(int x, int y) {
        this.x=x;
        this.y=y;

        for(Obserwator i : obserwatorzy)
            i.powiadomienie(x, y);
    }

    public void dodajObserwatora(Obserwator obserwator) {
        obserwatorzy.add(obserwator);
    }

    public void usunObserwatora(Obserwator obserwator) {
        obserwatorzy.remove(obserwator);
    }

}