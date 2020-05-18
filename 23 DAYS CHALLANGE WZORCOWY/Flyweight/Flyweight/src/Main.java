import java.util.Random;

public class Main {
    private static String[] TypGracza = {"AntyTerrorysta", "Terrorysta"};
    private static String[] Bronie = {"AK47", "M4A1", "AWP", "DGL"};

    public static String getRandTypGracza() {
        Random r = new Random();
        return TypGracza[r.nextInt(TypGracza.length)];
    }
    public static String getRandBron() {
        Random r = new Random();
        return Bronie[r.nextInt(Bronie.length)];
    }

    public static void main(String[] args) {
        for(int i=0; i<10; i++) {
            Gracz g = GraczFactory.getPlayer(getRandTypGracza());
            g.dodaj_bron(getRandBron());
            g.cel();
        }
    }
}


