package model;

import java.util.Random;

public class Fila implements Estrutura {
	
	Elemento no;
	
	public Fila() {
	
	}
	
	public Elemento getNo() {
		return no;
	}
	
	public void setNo(Elemento no) {
		this.no = no;
	}

	@Override
	public void construir() {
		
		Elemento no_a, no_b;
		Random randomNumbers;
		int valorCaracter;
		
		no_b = new Elemento();
		randomNumbers = new Random();
		
		for (int i = 0; i < 20; i++) {
			
			valorCaracter = 64 + randomNumbers.nextInt(22);
			
			if ((valorCaracter == 65) || (valorCaracter == 69) || (valorCaracter == 73) || (valorCaracter == 79) || (valorCaracter == 85)) {

				no_a = new Elemento((char) valorCaracter, null);
				
				if (this.getNo() == null)
					this.setNo(no_a);
				
				else
					no_b.setProx(no_a);
				
				no_b = no_a;
				
			}				
			
		}
		
		no_b.setProx(null);
		
	}
	
	@Override
	public void inserir(Object dado) {
		
		Elemento no_a, no_b;
		
		no_a = new Elemento(dado, null);
		
		if (this.getNo() == null)
			this.setNo(no_a);
		
		else {

			no_b = this.getNo();
			
			while (no_b.getProx() != null)
				no_b = no_b.getProx();
			
			no_b.setProx(no_a);
				
		}
		
	}
	
	public boolean isEmpty() {
		
		return (this.getNo() == null);
		
	}

	@Override
	public boolean procurar(Object dado) {
		
		Fila fila_a;
		boolean flag;
		
		flag = false;
		
		if (this.isEmpty())
			System.out.print("fila vazia");
		
		else {
			
			fila_a = new Fila();
			
			while (!this.isEmpty()) {
				
				if (this.raiz() == dado)
					flag = true;
				
				fila_a.inserir(this.raiz());
				this.remover();
				
			}
			
			while (!fila_a.isEmpty()) {
				
				this.inserir(fila_a.raiz());
				fila_a.remover();
			
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
			System.out.printf("fila vazia\n");
		
		else {
			
			raiz = this.getNo().getDado();
			this.setNo(this.getNo().getProx());
			
		}
		
		return raiz;
	
	}

	@Override
	public void remover(Object dado) {
		
		Fila fila_a;
		boolean flag;
		
		flag = false;
		
		if (this.isEmpty())
			System.out.print("fila vazia");
		
		else {
			
			fila_a = new Fila();
			
			while (!this.isEmpty()) {
				
				if (this.raiz() == dado) {
					
					flag = true;
					this.remover();
				
				} else {
					
					fila_a.inserir(this.raiz());
					this.remover();
					
				}
				
			}
			
			while (!fila_a.isEmpty()) {
				
				this.inserir(fila_a.raiz());
				fila_a.remover();
			
			}
				
		}
		
		if (!flag)
			System.out.println("elemento nao presente");
		
		else
			System.out.println("elemento removido");
		
	}

	@Override
	public void ler() {
		
		Fila fila_a;
		
		if (this.isEmpty())
			System.out.print("fila vazia");
		
		else {
			
			fila_a = new Fila();
			
			while (!this.isEmpty()) {
				
				fila_a.inserir(this.raiz());
				System.out.printf("%c", this.remover());
				
			}
			
			while (!fila_a.isEmpty()) {
				
				this.inserir(fila_a.raiz());
				fila_a.remover();
			
			}
				
		}
		
		System.out.println();
		
	}

}
