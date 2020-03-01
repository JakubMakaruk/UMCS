package pakunek;

import java.util.*;

public class Jamnik extends Pies {
    private String kolor;

    public Jamnik() {
    }

    public String getKolor() {
        return this.kolor;
    }

    public void setKolor(String s) {
        this.kolor = s;
    }

    public void zmierzDlugosc() {
        System.out.println("Jamnik ma: " + this.getDlugosc() + "m.");
    }

}