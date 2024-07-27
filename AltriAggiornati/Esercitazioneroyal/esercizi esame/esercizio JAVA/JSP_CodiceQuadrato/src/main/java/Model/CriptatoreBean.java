package Model;

public class CriptatoreBean {
    public static String cripta(String frase) {
        // Normalizzazione della frase
        String testoNormalizzato = frase.toLowerCase().replaceAll("[^a-z]", "");
        
        // Calcolo delle dimensioni del rettangolo
        int lunghezza = testoNormalizzato.length();
        int r = (int) Math.sqrt(lunghezza);
        int c = r;
        if (r * c < lunghezza) {
            c++;
        }
        if (c - r > 1) {
            r++;
        }

        // Costruzione della matrice
        char[][] matrice = new char[r][c];
        int k = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (k < lunghezza) {
                    matrice[i][j] = testoNormalizzato.charAt(k++);
                } else {
                    matrice[i][j] = ' ';  // Riempie gli spazi vuoti con uno spazio
                }
            }
        }

        // Codifica del messaggio
        StringBuilder codice = new StringBuilder();
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                codice.append(matrice[i][j]);
            }
            codice.append(' '); // Aggiunge uno spazio tra i blocchi
        }

        return codice.toString().trim();
    }
}