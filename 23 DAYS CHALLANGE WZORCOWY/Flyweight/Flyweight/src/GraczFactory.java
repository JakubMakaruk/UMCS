import java.util.*;
public class GraczFactory {
    private static HashMap<String, Gracz> mapaGraczy = new HashMap<String, Gracz>();

    public static Gracz getPlayer(String typ) {
        Gracz g = null;
        if(mapaGraczy.containsKey(typ))
            g = mapaGraczy.get(typ);
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
            mapaGraczy.put(typ, g);
        }
        return g;
    }
}

