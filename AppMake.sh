#!/bin/sh

g++ ServerModule/Server.cpp ServerModule/ServerMain.cpp RequestHandler/RequestHandler.cpp RequestHandler/Requests/RequestFactory.cpp RequestHandler/Requests/TrainReccomenderModels.cpp RequestHandler/Requests/GetReccomendationsRequest.cpp DataBase/DataBase.cpp LoggerModule/Logger.cpp MLModels/SVD.cpp Tests/SVDModelTest.cpp HNSW/HNSW.cpp HNSW/Node.cpp HNSW/Layer.cpp HNSW/Utils.cpp -o App -lpthread -lmysqlclient
