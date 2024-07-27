package it.cefi.controllers;

import java.io.IOException;

import it.cefi.model.CodiceQuadrato;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;




@WebServlet("/codicequadrato")
public class CodiceQuadratoServlet extends HttpServlet {
    /**
	 * 
	 */
	private static final long serialVersionUID = -909111859356099214L;

	/**
	 * 
	 */
	/*
	 * FUNZIOAVAAAAA
	private static final long serialVersionUID = 1L;
	
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String frase = request.getParameter("frase");
        CodiceQuadrato codiceQuadrato = new CodiceQuadrato(frase);
       
        
        request.setAttribute("codiceQuadrato", codiceQuadrato.getCodice());
        request.getRequestDispatcher("result.jsp").forward(request, response);
    }
	*/

	
	 @Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String frase = request.getParameter("frase");
        CodiceQuadrato codiceQuadrato = new CodiceQuadrato(frase);
        request.setAttribute("result", codiceQuadrato.getFrase());
        request.setAttribute("codice", codiceQuadrato.getCodice());
        request.getRequestDispatcher("result.jsp").forward(request, response);
    }
    
	/*
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String frase = request.getParameter("frase");
        CodiceQuadrato codiceQuadrato = new CodiceQuadrato(frase);
        request.setAttribute("codiceQuadrato", codiceQuadrato);
        response.sendRedirect("codicequadrato.jsp");
	}
	*/
}