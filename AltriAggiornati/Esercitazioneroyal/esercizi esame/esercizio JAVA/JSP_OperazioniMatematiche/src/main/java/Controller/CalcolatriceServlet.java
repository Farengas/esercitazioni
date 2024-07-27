package Controller;

import Model.Calcolatrice;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

@WebServlet("/calculate")
public class CalcolatriceServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String input = request.getParameter("input");
        String result;
        // Verifica che l'input non sia nullo e non sia vuoto (dopo aver rimosso gli spazi bianchi)
        if (input != null && !input.trim().isEmpty()) {
            try {
                double calculationResult = Calcolatrice.calculate(input);
                result = "Risultato: " + calculationResult;
            } catch (Exception e) {
                result = "Errore: " + e.getMessage();
            }
        } else {
            result = "Errore: l'input è vuoto.";
        }

        request.setAttribute("result", result);
        request.getRequestDispatcher("/index.jsp").forward(request, response);
    }
}
