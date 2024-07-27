package Model;

import net.objecthunter.exp4j.Expression;
import net.objecthunter.exp4j.ExpressionBuilder;

public class Calcolatrice {
    public static double calculate(String input) throws Exception {
        // Rimuovi spazi dall'input (Exp4j dovrebbe gestirli comunque)
        input = input.replaceAll("\\s+", "");

        // Verifica che l'input non sia vuoto
        if (input.isEmpty()) {
            throw new IllegalArgumentException("L'input non contiene un'operazione matematica valida.");
        }

        // Crea l'espressione usando Exp4j
        Expression expression = new ExpressionBuilder(input).build();
        
        try {
            // Calcola il risultato
            return expression.evaluate();
        } catch (Exception e) {
            // Gestisci eccezioni specifiche di Exp4j
            throw new IllegalArgumentException("Errore di calcolo: " + e.getMessage(), e);
        }
    }
}