public class CoDrugaLiteraMalaFormat implements Formatowanie {
    public String formatuj(String tekst) {
        char temp[] = tekst.toCharArray();

        for(int i=1; i<tekst.length(); i=i+2) {
            temp[i] = Character.toUpperCase(temp[i]);
        }
        return new String(temp);
    }
}