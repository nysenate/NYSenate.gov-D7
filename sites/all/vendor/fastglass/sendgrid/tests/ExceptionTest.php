<?php
namespace Fastglass\SendGrid\Tests;

class SendGridTest_Exception extends \PHPUnit_Framework_TestCase {

  public function tearDown() {
  }

  public function testConstructionException() {
    $err = new \Fastglass\SendGrid\Exception();
    $this->assertEquals(get_class($err), 'Fastglass\SendGrid\Exception');
  }

}
