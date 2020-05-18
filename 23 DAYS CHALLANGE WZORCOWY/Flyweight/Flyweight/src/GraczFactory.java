import java.util.*;
public class GraczFactory {
    private static HashMap<String, Gracz> mapaKwadratow = new HashMap<String, Gracz>();

    public static Gracz getPlayer(String typ) {
        Gracz g = null;
        if(mapaKwadratow.containsKey(typ))
            g = mapaKwadratow.get(typ);
        else
        {
            switch (typ) {
                case "AntyTerrorysta":
                    System.out.println("Stworzono AntyTerroryste");
                    g = new AntyTerrorysta();
                    break;
                case "Terrorysta":
                    System.out.println("Stworzono Terroryste");
                    g = new Terrorysta();
                    break;
            }
            mapaKwadratow.put(typ, g);
        }
        return g;
    }
}

