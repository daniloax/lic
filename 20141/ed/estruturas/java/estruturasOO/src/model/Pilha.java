package model;

import java.util.Random;

public class Pilha implements Estrutura {

	private Elemento no;
	
	public Pilha() {
		
	}
	
	public Elemento getNo() {
		return no;
	}
	
	public void setNo(Elemento no) {
		this.no = no;
	}
	
	@Override
	public void construir() {
		
		Elemento no_a;
		Random randomNumbers;
		int valorCaracter;
		
		randomNumbers = new Random();
		
		for (int i = 0; i < 20; i++) {
			
			valorCaracter = 64 + randomNumbers.nextInt(22);
			
			if ((valorCaracter == 65) || (valorCaracter == 69) || (valorCaracter == 73) || (valorCaracter == 79) || (valorCaracter == 85)) {

				no_a = new Elemento((char) valorCaracter, this.getNo());
				this.setNo(no_a);
				
			}				
			
		}

	}

	@Override
	public void inserir(Object dado) {
		
		Elemento no_a;
		
		no_a = new Elemento(dado, this.getNo());
		this.setNo(no_a);
		
	}
	
	public boolean isEmpty() {
		
		return (this.getNo() == null);
		
	}

	@Override
	public boolean procurar(Object dado) {
		
		Pilha pilha_a;
		boolean flag;
		
		flag = false;
		
		if (this.isEmpty())
			System.out.print("fila vazia");
		
		else {
			
			pilha_a = new Pilha();
			
			while (!this.isEmpty()) {
				
				if (this.raiz() == dado)
					flag = true;
				
				pilha_a.inserir(this.raiz());
				this.remover();
				
			}
			
			while (!pilha_a.isEmpty()) {
				
				this.inserir(pilha_a.raiz());
				pilha_a.remover();
			
			}
				
		}
		
		return flag;
		
	}

	@Override
	public Object raiz() {
		
		if (this.getNo() == null)
			return null;
		
		else
			return this.getNo().getDado();
		
	}

	@Override
	public Object remover() {
		
		Object raiz;
		
		raiz = null;
		
		if (this.getNo() == null)
			System.out.printf("pilha vazia\n");
		
		else {
			
			raiz = this.getNo().getDado();
			this.setNo(this.getNo().getProx());
			
		}
		
		return raiz;
	
	}

	@Override
	public void remover(Object dado) {
		
		Pilha pilha_a;
		boolean flag;
		
		flag = false;
		
		if (this.isEmpty())
			System.out.print("fila vazia");
		
		else {
			
			pilha_a = new Pilha();
			
			while (!this.isEmpty()) {
				
				if (this.raiz() == dado) {
					
					flag = true;
					this.remover();
				
				} else {
					
					pilha_a.inserir(this.raiz());
					this.remover();
					
				}
				
			}
			
			while (!pilha_a.isEmpty()) {
				
				this.inserir(pilha_a.raiz());
				pilha_a.remover();
			
			}
				
		}
		
		if (!flag)
			System.out.println("elemento nao presente");
		
		else
			System.out.println("elemento removido");
		
	}

	@Override
	public void ler() {
		
		Pilha pilha_a;
		
		if (this.isEmpty())
			System.out.print("fila vazia");
		
		else {
			
			pilha_a = new Pilha();
			
			while (!this.isEmpty()) {
				
				pilha_a.inserir(this.raiz());
				System.out.printf("%c", this.remover());
				
			}
			
			while (!pilha_a.isEmpty()) {
				
				this.inserir(pilha_a.raiz());
				pilha_a.remover();
			
			}
				
		}
		
		System.out.println();

	}

}
