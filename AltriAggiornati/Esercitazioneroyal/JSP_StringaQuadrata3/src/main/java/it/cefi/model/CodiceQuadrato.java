package it.cefi.model;

public class CodiceQuadrato {
    private String frase;
    private int colonne;
    private int righe;
    private String[][] rettangolo;
    private String codice;

    public CodiceQuadrato(String frase) {
        this.frase = frase;
        this.colonne = calcolaColonne(frase.length());
        this.righe = calcolaRighe(frase.length(), colonne);
        this.rettangolo = creaRettangolo(frase, righe, colonne);
        this.codice = codificaRettangolo(rettangolo);
    }

    public String getFrase() {
        return frase;
    }

    public int getColonne() {
        return colonne;
    }

    public int getRighe() {
        return righe;
    }

    public String[][] getRettangolo() {
        return rettangolo;
    }

    public String getCodice() {
        return codice;
    }

    private int calcolaColonne(int lunghezza) {
        int c = (int) Math.sqrt(lunghezza);
        while (c * (c - 1) < lunghezza) {
            c++;
        }
        return c;
    }

    private int calcolaRighe(int lunghezza, int c) {
        return (int) Math.ceil((double) lunghezza / c);
    }

    private String[][] creaRettangolo(String frase, int r, int c) {
        String[][] rettangolo = new String[r][c];
        int indice = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (indice < frase.length()) {
                    rettangolo[i][j] = frase.substring(indice, indice + 1);
                    indice++;
                } else {
                    rettangolo[i][j] = "";
                }
            }
        }
        return rettangolo;
    }

    private String codificaRettangolo(String[][] rettangolo) {
        StringBuilder codice = new StringBuilder();
        for (int j = 0; j < rettangolo[0].length; j++) {
            for (int i = 0; i < rettangolo.length; i++) {
                codice.append(rettangolo[i][j]);
            }
        }
        return codice.toString();
    }
}