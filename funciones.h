#define MAX_LIBROS 10

struct Libro {
    int id;
    char titulo[100];
    char autor[50];
    int anioPublicacion;
    char estado[15];
};

int registrarLibro(struct Libro libros[], int cantidadLibros);
void mostrarLibros(struct Libro libros[], int cantidadLibros);
int buscarLibroPorId(struct Libro libros[], int cantidadLibros, int id);
int buscarLibroPorTitulo(struct Libro libros[], int cantidadLibros, const char *titulo);
void mostrarInformacionLibro(struct Libro libro);
void actualizarEstadoLibro(struct Libro libros[], int cantidadLibros, int id);
int eliminarLibro(struct Libro libros[], int cantidadLibros, int id);

