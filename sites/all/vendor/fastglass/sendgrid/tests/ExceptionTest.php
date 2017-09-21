<?php
namespace SendGrid\Tests;

class SendGridTest_Exception extends \PHPUnit_Framework_TestCase {

  public function tearDown() {
  }

  public function testConstructionException() {
    $err = new \SendGrid\Exception();
    $this->assertEquals(get_class($err), 'SendGrid\Exception');
  }

}
