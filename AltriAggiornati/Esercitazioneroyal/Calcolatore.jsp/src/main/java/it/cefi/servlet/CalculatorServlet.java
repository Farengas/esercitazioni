package it.cefi.servlet;


import java.io.IOException;

import it.cefi.models.Calculator;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet("/calculator")
public class CalculatorServlet extends HttpServlet {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String input = request.getParameter("input");
        String[] parts = input.split(" ");
        Calculator calculator = new Calculator();

        for (String part : parts) {
            if (isNumeric(part)) {
                calculator.addNumber(Double.parseDouble(part));
            } else {
                calculator.addOperation(part);
            }
        }

        calculator.executeOperations();

        request.setAttribute("result", calculator.getResult());
        request.getRequestDispatcher("result.jsp").forward(request, response);
    }

    private boolean isNumeric(String str) {
        try {
            Double.parseDouble(str);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
}