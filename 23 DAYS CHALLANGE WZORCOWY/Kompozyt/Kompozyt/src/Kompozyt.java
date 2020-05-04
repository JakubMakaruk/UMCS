import java.util.*;
public class Kompozyt {
    public List<Ksztalt> ksztalty = new ArrayList<Ksztalt>();

    public void rysuj() {
        for(Ksztalt k : ksztalty) {
            k.rysuj();
        }
    }

    public void dodajKsztalt(Ksztalt k) {
        this.ksztalty.add(k);
    }

}