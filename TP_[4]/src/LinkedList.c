#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    if(this == NULL)
    {
    	this = (LinkedList*)malloc(sizeof(LinkedList));

    	if(this != NULL)
    	{
    		this->size = 0;
    		this->pFirstNode = NULL;
    	}
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int largoLista;
	int i;

	if(this != NULL)
	{
		largoLista = ll_len(this);

		if(nodeIndex >= 0 && nodeIndex < largoLista)
		{
			pNode = this->pFirstNode;

			for(i = 0; i < nodeIndex; i++)
			{
				pNode = pNode->pNextNode;
			}
		}
	}

	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int largoLista;
    Node* pNuevoNodo = NULL;
    Node* pNodoAuxiliar = NULL;
    int nodoAnteriorConElIndiceSiguiente;

    nodoAnteriorConElIndiceSiguiente = nodeIndex - 1;

    if(this != NULL)
    {
    	largoLista = ll_len(this);

    	if(nodeIndex >= 0 && nodeIndex <= largoLista)
    	{
    		pNuevoNodo = (Node*)malloc(sizeof(Node));

    		if(pNuevoNodo != NULL)
    		{
    			if(nodeIndex == 0)	// si es el primero
    			{
    			    pNodoAuxiliar = this->pFirstNode;
    			    this->pFirstNode = pNuevoNodo;
    			    pNuevoNodo->pNextNode = pNodoAuxiliar;
    			}
    			else
    			{
    				pNodoAuxiliar = getNode(this,nodoAnteriorConElIndiceSiguiente);
    				pNodoAuxiliar->pNextNode = pNuevoNodo;
    				pNuevoNodo->pNextNode = getNode(this,nodeIndex);

    				/*
    				//VERIFICAR
    				if(nodeIndex == largoLista) // si es el final
    			    {
    					pNodoAuxiliar = getNode(this,nodoAnteriorConElIndiceSiguiente);
    			    	pNodoAuxiliar->pNextNode = pNuevoNodo;
    			    	pNuevoNodo->pNextNode = NULL;
    			    }
    			    else // si es por otro lugar
    			    {
    			    	pNodoAuxiliar = getNode(this,nodoAnteriorConElIndiceSiguiente);
    			    	pNodoAuxiliar->pNextNode = pNuevoNodo;
    			    	//pNuevoNodo->pNextNode = getNode(this,nodoIndiceAnterior);
    			    	pNuevoNodo->pNextNode = getNode(this,nodeIndex);
    			    }
    			    */
    			}
            	pNuevoNodo->pElement = pElement;
            	this->size++;
            	returnAux = 0;
    		}
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int largoLista;

    if(this != NULL)
    {
    	largoLista = ll_len(this);

    	if(addNode(this, largoLista, pElement) == 0)
    	{
    	    returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int largoLista;
    Node* pNodeAuxiliar;

    if(this != NULL)
	{
    	largoLista = ll_len(this);

    	if(index >= 0 && index < largoLista)
    	{
    		pNodeAuxiliar = getNode(this, index);

    		if(pNodeAuxiliar != NULL)
    		{
    			returnAux = pNodeAuxiliar->pElement;
    		}
    	}
	}

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNodeAuxiliar;
    int largoLista;

    if(this != NULL)
    {
    	largoLista = ll_len(this);

    	if(index >= 0 && index < largoLista)
    	{
        	pNodeAuxiliar = getNode(this, index);

        	if(pNodeAuxiliar != NULL)
        	{
        		pNodeAuxiliar->pElement = pElement;
            	returnAux = 0;
        	}
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int largoLista;
    Node* pNodoAuxiliar;
    Node* pNodoAuxiliarNodoAnterior;
    int nodoAnteriorConElIndiceSiguiente;

    nodoAnteriorConElIndiceSiguiente = index - 1;

    if(this != NULL)
    {
    	largoLista = ll_len(this);

    	//if(index >= 0 && index <= largoLista)
    	if(index >= 0 && index < largoLista)
    	{
    		pNodoAuxiliar = getNode(this, index);

    		if(index == 0)
    		{
        		this->pFirstNode = pNodoAuxiliar->pNextNode; //le paso el proximo nodo al que voy a borrar a la cabeza
        		pNodoAuxiliar->pNextNode = NULL; //al que borre lo hago apuntar a NULL
    		}
    		else
    		{
    			pNodoAuxiliarNodoAnterior = getNode(this,nodoAnteriorConElIndiceSiguiente);
    			pNodoAuxiliarNodoAnterior->pNextNode = pNodoAuxiliar->pNextNode;
    			/*
    			//VERIFICAR
    			if(index == largoLista)
    			{
    				pNodoAuxiliarOtro = getNode(this,nodoAnteriorConElIndiceSiguiente);
    				pNodoAuxiliarOtro->pNextNode = NULL;
    			}
    			else
    			{
    				pNodoAuxiliarOtro = getNode(this,nodoAnteriorConElIndiceSiguiente);
    				pNodoAuxiliarOtro->pNextNode = pNodoAuxiliar->pNextNode;
    				pNodoAuxiliar->pNextNode = NULL; //MIRAR
    			}
    			*/
    		}
    		free(pNodoAuxiliar);
    		this->size--;
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int largoLista;
    int i;

    if(this != NULL)
    {
    	largoLista = ll_len(this);

    	for(i = 0; i < largoLista; i++)
    	{
    		ll_remove(this, i);
    	}

    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_clear(this) == 0)
    	{
        	free(this);
        	returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int largoLista;
    int i;
    void* pElementAuxiliar;

    if(this != NULL)
    {
    	largoLista = ll_len(this);

    	for(i = 0; i < largoLista; i++)
    	{
    		pElementAuxiliar = ll_get(this, i);

    		if(pElementAuxiliar == pElement)
    		{
    			returnAux = i;

        		break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int largoLista;

    if(this != NULL)
    {
    	returnAux = 1;

    	largoLista = ll_len(this);

    	if(largoLista != 0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int largoLista;

    if(this != NULL)
    {
    	largoLista = ll_len(this);

    	if(index >= 0 && index <= largoLista)
    	{
    		if(addNode(this, index, pElement) == 0)
    		{
            	returnAux = 0;
    		}
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int largoLista;
    void* pElementoAuxiliar;

    if(this != NULL)
    {
    	largoLista = ll_len(this);

    	if(index >= 0 && index < largoLista)
    	{
    		//returnAux = ll_get(this, index); //[EL AUXILIAR DEL PELEMENT LO ARREGLA]
    		pElementoAuxiliar = ll_get(this, index);

    		//this->size--; //[SI NO ESTA ME TIRA 3 ERRORES, PROBLEMA EN EL REMOVE?] [YA NO HACE FALTA]

   			//if(ll_remove(this, index) != 0)
       		//if(ll_remove(this, index) == 0)	//VERIFICAR
    		//if(pElementoAuxiliar != NULL && ll_remove(this, index) == 0) // [PREGUNTAR SI PREGUNTO POR EL PELEMENT NULL]
       		if(ll_remove(this, index) == 0) //[ARREGLADO CON UN AUXILIAR PARA LA DIRECCION]
    		{
       			//returnAux = ll_get(this, index); // <- si ya lo elimine deberia tomarlo antes
    			//this->size--;
       			//returnAux = NULL;
       			returnAux = pElementoAuxiliar;
    		}
    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int resultado;

    if(this != NULL)
    {
    	returnAux = 0;

    	resultado = ll_indexOf(this, pElement);

    	if(resultado >= 0)
    	{
    		returnAux = 1;
    	}
    }

	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int largoLista;
    int i;
    void* pElement;

    if(this != NULL && this2 != NULL)
    {
    	largoLista = ll_len(this2);

    	for(i = 0; i <= largoLista; i++)
    	{
    		returnAux = 1;
    		//pElement = ll_get(this, i);
    		pElement = ll_get(this2, i);

    		if(pElement != NULL) //[NECESARIO QUE EL ELEMENTO TENGA ALGO?]
    		{
    			if(ll_contains(this, pElement) == 0) //si no esta retorno 0
    			{
    				returnAux = 0;
    				break; //[SI UNO NO ESTA YA CORTO LA ITERACION]
    			}
    			//else
    			//{
    		    //	returnAux = 1;
    			//}
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int largoLista;
    int i;
    void* pElement;
    LinkedList* cloneAuxiliar = NULL;

    if(this != NULL)
    {
    	largoLista = ll_len(this);

    	if(from >= 0 && from <= largoLista && to >= from && to <= largoLista)
    	{
    		cloneAuxiliar = ll_newLinkedList();
    		//cloneArray = ll_newLinkedList();

    		//if(cloneArray != NULL)
    		if(cloneAuxiliar != NULL)
    		{
    			for(i = from; i < to; i++)
    			{
    				pElement = ll_get(this, i);

    				//ll_add(cloneArray, pElement);
    				//ll_add(cloneArray, pElement); //AGREGAR
    				// [PREGUNTAR] if con add y Retorno modificar si el add pudo o no agregar?
    				if(ll_add(cloneAuxiliar, pElement) == 0)
    				{
    					cloneArray = cloneAuxiliar;
    				}
    				//free(cloneAuxiliar);
    			}
    		}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int largoLista;

    if(this != NULL)
    {
    	largoLista = ll_len(this);

    	cloneArray = ll_subList(this, 0, largoLista);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int largoLista;
    int i;
    int j;
    void* pElementUno;
    void* pElementDos;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	largoLista = ll_len(this);

        for(i = 0; i < largoLista - 1; i++)
        {
        	for(j = i + 1; j < largoLista; j++)
        	{
        		pElementUno = ll_get(this, i);
        		pElementDos = ll_get(this, j);

        		if((pFunc(pElementUno ,pElementDos) < 0 && order == 0) || (pFunc(pElementUno ,pElementDos) > 0 && order == 1))
        		{
        			ll_set(this, i, pElementDos);
        			ll_set(this, j, pElementUno);
        		}
        	}
        }

        returnAux = 0;
    }

    return returnAux;

}

