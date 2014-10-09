package view;

import model.Fila;
import model.Lista;
import model.Malha;
import model.Pilha;

public class Principal {
	
	public static void main(String[] args) {
		
		Lista lista_a = new Lista();
		lista_a.construir();
		lista_a.ler();
		lista_a.inserir('A');
		lista_a.ordenar();
		lista_a.ler();
		System.out.printf("%s\n", lista_a.procurar('U'));
		System.out.printf("%s\n", lista_a.raiz());
		lista_a.remover('U');
		lista_a.ler();
		
		Lista lista_b = new Lista();
		lista_b.construir();
		lista_b.ler();
		
		Lista lista_c = new Lista();
		lista_c.concatenar(lista_a, lista_b);
		lista_c.ler();
		lista_c.ordenar();
		lista_c.ler();
		
		Fila fila_a = new Fila();
		fila_a.construir();
		fila_a.ler();
		fila_a.inserir('A');
		fila_a.ler();
		System.out.printf("%s\n", fila_a.procurar('U'));
		fila_a.remover('U');
		fila_a.ler();
		
		Pilha pilha_a = new Pilha();
		pilha_a.construir();
		pilha_a.ler();
		pilha_a.inserir('A');
		pilha_a.ler();
		System.out.printf("%s\n", pilha_a.procurar('U'));
		pilha_a.remover('U');
		pilha_a.ler();
		
		Malha malha_a = new Malha(); 
		malha_a.construir();
		malha_a.ler();
		
	}

}
