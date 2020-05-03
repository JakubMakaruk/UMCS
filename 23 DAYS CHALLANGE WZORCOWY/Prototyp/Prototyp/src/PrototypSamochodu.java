public abstract class PrototypSamochodu implements Cloneable {
    protected String nazwa;
    protected String model;

    @Override
    public Object clone(){
        try {
            PrototypSamochodu copy = (PrototypSamochodu) super.clone();
            return copy;
        }
        catch (CloneNotSupportedException e) {
            e.printStackTrace();
            return null;
        }
    }

    public String getNazwa() {
        return this.nazwa + " " + this.model;
    }
    public void setModel(String s) {
        this.model = s;
    }
}