package Controller;

import Model.CriptatoreBean;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

@WebServlet("/cripta")
public class CriptatoreServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String frase = request.getParameter("frase");
        String messaggioCriptato;
        // Controlla se la frase non è nulla e non è vuota (dopo aver rimosso gli spazi iniziali e finali)
        if (frase != null && !frase.trim().isEmpty()) {
            messaggioCriptato = CriptatoreBean.cripta(frase);
        } else {
            messaggioCriptato = "Errore: l'input è vuoto.";
        }

        request.setAttribute("risultato", messaggioCriptato);
        request.getRequestDispatcher("/index.jsp").forward(request, response);
    }
}
