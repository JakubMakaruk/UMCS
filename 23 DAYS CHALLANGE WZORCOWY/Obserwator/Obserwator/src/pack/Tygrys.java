package pack;

public class Tygrys implements Obserwator {

    public float x;
    public float y;

    public Tygrys(float x, float y) {
        this.x = x;
        this.y= y;
    }

    public void atakuj() {
        System.out.println("Tygrys atakuje!");
    }

    @Override
    public void powiadomienie(float x, float y) {
        if(this.x==x && this.y==y)
            atakuj();
    }
}