package test;

import model.Lista;

import org.junit.Assert;
import org.junit.Test;


public class ListaTest {

	@Test
	public void construir() {
		
		Lista lista = new Lista();
		Assert.assertNotNull(lista);
		
	}

	@Test
	public void inserir() {
		
		Lista lista = new Lista();
		lista.inserir('A');
		Assert.assertTrue(lista.procurar('A'));
		
	}

	@Test
	public void procurar() {
		
		Lista lista = new Lista();
		lista.inserir('A');
		Assert.assertTrue(lista.procurar('A'));
		
	}

	@Test
	public void raiz() {
		
		Lista lista = new Lista();
		lista.inserir('A');
		Assert.assertEquals(lista.raiz(), 'A');
		
	}

	@Test
	public void removerDado() {
		
		Lista lista = new Lista();
		lista.inserir('A');
		lista.remover('A');
		Assert.assertNull(lista.getNo());
		
	}
	
	@Test
	public void removerRaiz() {
		
		Lista lista = new Lista();
		lista.inserir('A');
		lista.remover();
		Assert.assertNull(lista.getNo());
		
	}

}
