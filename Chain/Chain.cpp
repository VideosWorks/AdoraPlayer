
#include "Chain.h"

Chain::Chain(Chain *chain)
	:chain(chain) {

}

Chain::~Chain() {


}

void Chain::request(Request* request) {

	this->chain->request(request);
}