#ifndef _EXCHANGE_HPP
#define _EXCHANGE_HPP

namespace Exchange {
    struct Ticker {
        const char* name;

        Ticker(const char* name) : name(name) {
            
        }
    };

    class Exchange {
        static Exchange* exchange;

        Exchange() {
            
        }
    public:
        static Exchange& getExchange() {
            if (exchange) return *exchange;
            exchange = new Exchange();
            return *exchange;
        }


        static void destroy() {
            delete exchange;
        }
        void close() {

        }
    };

    Exchange* Exchange::exchange = nullptr;
};


#endif

