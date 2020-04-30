
public class KreatorMiecznika implements KreatorPostaci {

    public KreatorMiecznika() {
    }


    @Override
    public Postac stworz() {
        return new Miecznik();
    }
}