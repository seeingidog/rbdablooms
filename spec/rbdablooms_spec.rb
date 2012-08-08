require File.expand_path(File.dirname(__FILE__) + '/spec_helper')

describe "Rbdablooms" do
  before :each do 
    @bloom = Dablooms.new(:capacity=>1000, :error_rate=>0.05, :filepath=>'/tmp/bloom.bin', :id=>1)
  end
  
  it "adds an element to the set" do
    @bloom.add('foo', 2).should == 1
  end
  
  it "adds an element to the set and checks for it's existance" do
    @bloom.add('bar', 2)
    @bloom.check('bar').should == 1
  end
  
  it "checks for an element that does not exist in set" do
    @bloom.check('bar').should == 0
  end
  
  it "deletes an element from the set" do
    @bloom.add('foo', 2)
    @bloom.delete('foo', 2).should == 0
  end
end
