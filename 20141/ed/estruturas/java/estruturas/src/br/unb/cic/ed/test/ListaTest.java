package br.unb.cic.ed.test;

import java.util.Random;

import br.unb.cic.ed.struct.Arvore;
import br.unb.cic.ed.struct.Elemento;
import br.unb.cic.ed.struct.Fila;
import br.unb.cic.ed.struct.Lista;
import br.unb.cic.ed.struct.Malha;
import br.unb.cic.ed.struct.Pilha;

public class ListaTest {

	public static void main(String[] args) {
		
		int dadoBusca, dadoInsercao;
		Elemento no_a, no_b, no_c, no_d, no_e;
		
		Random randomNumbers = new Random();
		
		dadoBusca = 65 + randomNumbers.nextInt(57);
		dadoInsercao = 65 + randomNumbers.nextInt(57);
		
		Lista lista = new Lista();
		no_a = lista.construir(null);
		no_b = lista.construir(null);
		
		lista.ler(no_a);
		lista.ler(no_b);
		
		lista.inserir(no_a, dadoInsercao);
		lista.inserir(no_b, dadoInsercao);
		
		lista.remover(no_a, (char) dadoBusca);
		lista.remover(no_b, (char) dadoBusca);
		
		lista.ler(no_a);
		lista.ler(no_b);
		
		no_c = lista.concatenar(no_a, no_b);
		lista.ler(no_c);
		
		lista.ordenar(no_c);
		lista.ler(no_c);
		
		Fila fila = new Fila();
		fila.inserir(no_c, 'a');
		
		lista.ler(no_c);
		
		fila.ler(no_c);
		
		Pilha pilha = new Pilha();
		no_c = pilha.inserir(no_c, 'a');
		
		lista.ler(no_c);
		
		pilha.ler(no_c);
		
		Malha malha = new Malha();
		no_d = malha.construir(null);
		malha.ler(no_d);
		
		Arvore arvore = new Arvore();
		no_e = arvore.construir(no_c);
		
		arvore.ler(no_e);
		System.out.printf("\n%b", arvore.estaBalanceada(no_e));
		System.out.printf("\n%d", arvore.altura(no_e));

		
	}

}
