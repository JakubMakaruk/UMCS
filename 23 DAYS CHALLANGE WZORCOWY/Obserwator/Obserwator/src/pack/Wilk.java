package pack;

public class Wilk implements Obserwator {

    public float x;
    public float y;

    public Wilk(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public void atakuj() {
        System.out.println("Wilk atakuje!");
    }

    @Override
    public void powiadomienie(float x, float y) {
        if(this.x==x && this.y==y)
            atakuj();
    }
}