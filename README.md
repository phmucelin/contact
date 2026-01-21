# Contact Manager

Um projeto em C que implementa um sistema CRUD para gerenciar contatos.
Permite adicionar, remover, buscar, editar contatos e exportar para Excel.

## Funcionalidades

- Adicionar contato (nome, email, telefone)
- Remover contato
- Buscar contato por nome, email ou telefone
- Editar contato
- Salvar/carregar contatos em arquivo txt
- Ordenar lista de contatos
- Exportar contatos para arquivo Excel (.xlsx)

## Como compilar

### Dependências

- GCC
- Biblioteca xlsxio (para export Excel)
- minizip e expat (instalados via Homebrew)

Instale as dependências:

```bash
brew install minizip libzip
```

Clone e compile a biblioteca xlsxio:

```bash
git clone https://github.com/brechtsanders/xlsxio.git
cd xlsxio
make
cd ..
```

Compile o projeto:

```bash
gcc contact.c -I./xlsxio/include -L./xlsxio -L/opt/homebrew/lib -lxlsxio_write -lminizip -lexpat -o contact
```

## Como executar

```bash
./contact
```

Siga o menu interativo.

## Estrutura do código

- `contact.c`: Código principal
- `xlsxio/`: Biblioteca externa para Excel
- `contatos.txt`: Arquivo de dados (opcional)
