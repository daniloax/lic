package br.unb.cic.ed.faces;

import java.util.Scanner;


public class Input {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		String string;
		char[] expressao;
		
		System.out.println("Entre com a expressão: ");
		string = input.nextLine();
		input.close();
		
		string = string.trim();
		expressao = string.toCharArray();
		
		
		for (int i = 0; i < expressao.length; i++)
			System.out.printf("%s", expressao[i]);

	}

}
