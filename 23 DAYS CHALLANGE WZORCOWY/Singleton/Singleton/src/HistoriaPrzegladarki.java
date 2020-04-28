public class HistoriaPrzegladarki {
    private static HistoriaPrzegladarki instancja = null;
    private String napis;


    private HistoriaPrzegladarki() {
        napis="";
        System.out.println("Utworzono jedyny obiekt typu HistoriaPrzegladarki(SINGLETON)");
    }
    public static HistoriaPrzegladarki getInstance() {
        if (instancja == null)
            instancja = new HistoriaPrzegladarki();
        return instancja;
    }

    public void setNapis(String napis) {
        this.napis = napis;
    }
    public String getNapis() {
        return napis;
    }
}

