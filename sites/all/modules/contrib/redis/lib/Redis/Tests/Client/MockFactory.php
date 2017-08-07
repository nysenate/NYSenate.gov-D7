<?php

class Redis_Tests_Client_MockFactory implements Redis_Client_FactoryInterface
{
    public function getClient($options = array())
    {
        return (object)$options;
    }

    public function getName()
    {
        return 'Mock';
    }
}