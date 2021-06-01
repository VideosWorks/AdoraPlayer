
#ifndef _CHAIN_H
#define _CHAIN_H

class Request;

class Chain {

protected:
	Chain* chain;

public:
	Chain(Chain* chain = nullptr);
	virtual ~Chain() = 0;

	void setChain(Chain* chain) { this->chain = chain; }

	virtual void request(Request* request);

};

#endif //_CHAIN_H