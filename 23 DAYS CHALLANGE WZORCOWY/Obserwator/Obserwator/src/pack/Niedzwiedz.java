package pack;

public class Niedzwiedz implements Obserwator {
    public float x;
    public float y;

    public Niedzwiedz(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public void atakuj() {
        System.out.println("Niedzwiedz atakuje!");
    }

    @Override
    public void powiadomienie(float x, float y) {
        if(this.x==x && this.y==y)
            atakuj();
    }
}